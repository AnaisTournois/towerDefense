/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2015  Guillaume L. <guillaume.lozenguez@mines-douai.fr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MIA_COLLECTION_H
#define MIA_COLLECTION_H


#include <list>
#include <iostream>
#include <math.h>

/**
 * Template Collection allocate an flexible array.
 *
 * TODO: rendre se patron conforme à la STD (iterator et const_iterator)
 *
 */

namespace mia {

template<class Obj>
class collection
{
public :

private :
        Obj ** a_item;
        std::list<int> a_freeId;
        int a_nextId, a_capacity;

public :
        /// Constructor destructor :
        ///-------------------------
        collection(int cap = 1)
        {
                a_nextId= 0;
                a_capacity= cap;
                a_item = new Obj*[a_capacity];
                for (int i= 0; i < a_capacity; i++)
                        a_item[i]= NULL;
                a_freeId.clear();
        };

        virtual ~collection()
        {
                for (int i= 0; i < a_capacity; i++)
                        if ( a_item[i] != NULL )
                                delete a_item[i];

                delete [] a_item;
        };

        /// assignement :
        ///--------------
        virtual const collection<Obj> & operator=(const collection<Obj> & colec)
        {
                // Delete :
                for (int i= 0; i < a_capacity; i++)
                        if ( a_item[i] != NULL )
                        delete a_item[i];

                delete [] a_item;

                // Init parameters :
                a_nextId= colec.a_nextId;
                a_capacity= colec.a_capacity;

                // init structure :
                a_item = new Obj*[a_capacity];
                for (int i= 0; i < a_capacity; i++)
                        a_item[i]= NULL;
                a_freeId.clear();

                // Copie :
                for( int i= colec.firstId(); i < colec.limit(); i= colec.nextId(i) )
                {
                        a_item[i]= new Obj;
                        (*a_item[i])= colec(i);
                }
                a_freeId= colec.a_freeId;

                return *this;
        }

        /// Initialize :
        ///-------------
        void initialize(int size= 0)
        {
                for (int i= 0; i < a_capacity; i++)
                if ( a_item[i] != NULL )
                delete a_item[i];

                delete [] a_item;

                a_nextId= 0;
                a_freeId.clear();

                a_capacity= std::max(size, 1);
                a_item = new Obj*[a_capacity];

                for (int i= 0; i < a_capacity; ++i)
                        a_item[i]= NULL;
        }

        void initialize( int size, const Obj & obj )
        {
                initialize(size);
                for (int i= 0; i < size; i++)
                        push(obj);
        }

        void initialize(int size, Obj* tab)
        {
                initialize(size);
                for (int i= 0; i < size; i++)
                push( tab[i] );
        }

        /// std standard :
        ///---------------
        int push(const Obj &obj= Obj())
        {
                int newid;
                if( a_freeId.empty() )
                {
                        newid= a_nextId;
                        a_nextId++;
                        if( a_nextId >= a_capacity )
                        resize( a_capacity + 1 );
                }
                else
                {
                        newid= a_freeId.front();
                        a_freeId.pop_front();
                }

                a_item[newid]= new Obj;
                (*a_item[newid])= obj;

                return newid;
        }

        /// getter and setter :
        ///--------------------
        inline int size()const{ return a_nextId - a_freeId.size(); }
        inline bool empty()const{ return ( size() < 1 ); }
        inline int capacity()const{ return a_capacity; }
        inline int limit()const{ return a_nextId; }
        inline int firstId()const
        {
                int id= 0;
                while( (id < a_nextId) && a_item[id] == NULL )
                        ++id;

                return id;
        }

        inline int nextId(int id)const
        {
                ++id;
                while( (id < a_nextId) && a_item[id] == NULL )
                        ++id;
                return id;
        }

        inline int getNextId()const
        {
                if( a_freeId.empty() )
                        return a_nextId;
                else
                        return a_freeId.front();
        }

        void set( int i, const Obj &obj= Obj() )
        {
                if( i < a_nextId && a_item[i] != NULL )
                        *a_item[i] = obj;
                else if( i < a_nextId )
                {
                        a_item[i]= new Obj();
                        *a_item[i] = obj;
                        a_freeId.remove(i);
                }
                else
                {
                        if( i < a_capacity )
                                resize(i);

                        for(a_nextId; a_nextId < i; ++a_nextId)
                                a_freeId.push_back(a_nextId);

                        a_item[i]= new Obj();
                        *a_item[i] = obj;

                        ++a_nextId;
                }
        }

        Obj get(int i)const{ return (*a_item[i]); }

        inline Obj& operator[](int i){ return (*a_item[i]); }
        inline const Obj & operator()(int i)const{ return (*a_item[i]); }

        void remove(int i)
        {
                if( isId(i) )
                {
                        delete a_item[i];
                        a_item[i]= NULL;

                        if( i == (a_nextId - 1) )
                        {
                                --a_nextId;

                                while( a_freeId.back() == (a_nextId - 1))
                                {
                                        --a_nextId;
                                        a_freeId.pop_back();
                                }
                        }
                        else
                        {
                                a_freeId.push_back(i);
                                a_freeId.sort();
                                a_freeId.unique();
                        }
                }
        }

 /// Boolean test :
 ///---------------
        inline bool isId(int i)const{ return (i >= 0) && (i < a_nextId) && a_item[i] != NULL; }

        /// Size :
        ///-------
        void increaseCapacity(int add){ resize( a_capacity + add ); }
        void resize(int size)
        {
                if ( size > a_capacity )
                {
                Obj * oldItem[a_capacity];

                for (int i= 0; i < a_capacity; i++)
                oldItem[i]= a_item[i];

                delete [] a_item;
                a_item= new Obj*[size];

                for (int i= 0; i < a_capacity; i++)
                a_item[i]= oldItem[i];

                for (int i= a_capacity; i < size; i++)
                a_item[i]= NULL;

                a_capacity= size;
                }
        }
};

};

#endif // MIA_COLLECTION_H
