
#ifndef __QUEUEBASE_H__
#define __QUEUEBASE_H__

template<typename T>

class QueueBase {

    protected:
        int _size;

    public:
        QueueBase() { _size = 0; } 
        virtual ~QueueBase() {   }

	 //Common helper methods

        virtual bool isEmpty() { return (_size == 0); }
        virtual int get_size(){ return _size; }

 	 //Major operations of queue
        virtual bool enqueue( const T& newitem ) = 0;
        virtual bool dequeue( T& item ) = 0; 

        virtual bool getFront( T& queueFront ) = 0;

};
#endif