/*
 * Copyright (C) 2022 FreeLancer Development Team
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
 */

/* 
 * File:   Object.h
 * Author: Javier Marrero
 *
 * Created on February 13, 2022, 2:25 PM
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <amanda-vm/Class.h>
#include <amanda-vm/ReferenceCounted.h>
#include <amanda-vm/String.h>

namespace amanda
{
namespace core
{


#define AMANDA_OBJECT(Type, Super) \
    private: \
        typedef Type    ClassName; \
        typedef Super   BaseClassName; \
    \
        typedef Super   super; \
    public: \
        \
        static amanda::core::Class& getClass() { static amanda::core::Class _class(#Type, &BaseClassName::getClass()); return _class; } \
        static size_t               getClassSizeStatic() { return sizeof(Type); } \
        \
        template <class __class> \
        __class& cast() \
        { \
            return static_cast<__class*> (this)->getReference(); \
        } \
        \
        virtual amanda::core::Class& getClassDynamically() const { return getClass(); } \
        \
        inline Type&                getReference() { return *this; }\
        inline const Type&          getConstReference() const { return *this; } \
        inline const Type* const    getSelfPointer() const { return this; } \
        \
        AMANDA_REFCOUNTED(ClassName) \
        \
        private:

/**
 * The <code>Object</code> class is the base class for all the Amanda Framework
 * types. It provides several utilities, including runtime type information
 * and reference counting (via the <code>ReferenceCounted</code>) class.
 * <p>
 * This mechanism ensures any object can be casted to and from an <code>Object</code>
 * reference. It also provides a way to clone an object.
 *
 * @author J. Marrero
 */
class Object : virtual public ReferenceCounted
{
public:

    static Class& getClass();
    static size_t getClassSizeStatic();

    Object();
    Object(const Object& original);
    virtual ~Object();

    virtual Object*                 clone() const;
    virtual bool                    equals(const Object* object);
    virtual amanda::core::Class&    getClassDynamically() const;
    virtual size_t                  getClassSize() const;
    virtual int                     hashCode();
    virtual bool                    is(const Class* type);
    virtual String                  toString() const;

    template <class T>
    bool is() const
    {
        return getClassDynamically().is(T::getClass());
    }

    template <class T>
    T* clone()
    {
        return new T(this);
    }

    virtual bool operator==(const Object& rhs);
    virtual bool operator==(const Object* rhs);

} ;

}
}

#endif /* OBJECT_H */

