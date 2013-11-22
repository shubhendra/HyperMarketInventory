
#ifndef __STACKBASE_H__
#define __STACKBASE_H__

template<typename T>
class StackBase {
    protected:
        int _size;

    public:
        StackBase() { _size = 0; } 
        virtual ~StackBase() {   }

        virtual bool isEmpty() { return (_size == 0); }
        virtual int size(){ return _size; }

        virtual bool push( const T& newItem ) = 0;
        virtual bool pop( T& stackTop ) = 0; 

        virtual bool getTop( T& stackTop ) = 0;

};
#endif