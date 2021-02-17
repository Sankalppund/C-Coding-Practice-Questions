/*Locks implementation prototype using
  atomic instructions such as 
   1:test-and-set
   2:Compare-and-swap
   3:xchg
  Locks: Spinlock
       : Mutex
       : rwlock using Mutex
       : semaphore   
*/

/***Test-and-set***/
/*flag is 0 initially
  Description: This test-and-set function
  checks if flag is false. if it is false
  then change it to true and return true
  or return false.
*/

bool flag = false; //flag should be atomic

bool test-and-set(){
    
    if(flag==false){
        flag=true;
        return true;
    }
    else{
        return false;
    }
}

/***Test-and-set***/
/*Checks the value at memory location
  CHECKS the old value, set the lock 
  value at memory location to 1 and 
  returns old value
  If unlocked then would return 0
  if already locked would return 1
*/  
int test_and_set(int*Lock){
    
    int old = *Lock;
    *Lock=1;
    return old;
}

/***Comapre-and-swap***/
/*Atomically checks if old value is what you
  expect, if it is, replace it with new value
  and indicate success*/
int val; //Should be atomic  

bool compare-and-swap(int expected, int new){
    
    if(val==expected){
       val=new;
       return true;
    }
    else{
        return false;
    }
    
}  

/*XCHG Instruction*/
/*Write to a memory location and
returns its old value*/

int xchg(int*lock, int val){
    
    int old = *lock;
    *lock=val;
    return old;
}
  
  
/*Spinlock using xchg*/
/*has two states lock and unlock
Thread keeps busy waiting on loop
till it gets the thread*/

/*lock*/
void Spinlock_lock(int*locked){
    
    while(1){
        
        /*breaks while loop only when
        xchg returns 0 i.e. lock isn't held
        by any other thread*/
        if(xchg(&locked,1)==0){
            break;
        }
    }
    
}

/*unlock*/
void Spinlock_unlock(int*locked){
    
    *locked=0;
}


/*Spinlock using TAS*/
/*has two states lock and unlock
Thread keeps busy waiting on loop
till it gets the thread*/

/*lock*/
void Spinlock_lock(int*locked){
    
    while(1){
        
        /*breaks while loop only when
        xchg returns 0 i.e. lock isn't held
        by any other thread*/
        if(test_and_set(&locked)==1){
            break;
        }
    }
    
}

/*unlock*/
void Spinlock_unlock(int*locked){
    
    *locked=0;
}


/*****Mutex Lock****/
/*Mutex using xchg instruction.
Process or thread yeilds/sleep
on CPU if lock is unavailable and 
do not keep busy waiting on CPU
and thus saves lots of CPU cycle*/

/*Lock*/
void mutex_lock(int*locked){
    
    while(1){
        
        if(xchg(&locked,1)==0){
            break;
        }
        else{
            //add this process to queue
            sleep();
        }
    }
    
}

/*Unlock*/
void mutex_unlock(int*locked){
    
    *locked=0;
    //remove this process from queue
    wakeup();
}


/*****Mutex Lock****/
/*Mutex using TAS instruction. Process 
or thread yeilds/sleep
on CPU if lock is unavailable and 
do not keep busy waiting on CPU
and thus saves lots of CPU cycle*/

/*Lock*/
void mutex_lock(int*locked){
    
    while(1){
        
        if(test_and_set(&locked)==1){
            break;
        }
        else{
            //add this process to queue
            sleep();
        }
    }
    
}

/*Unlock*/
void mutex_unlock(int*locked){
    
    *locked=0;
    //remove this process from queue
    wakeup();
}


/*****Mutex Lock****/
/*Mutex using TAS instruction. Process 
or thread yeilds/sleep
on CPU if lock is unavailable and 
do not keep busy waiting on CPU
and thus saves lots of CPU cycle*/

/*Lock*/
void mutex_lock(int*locked){
    
    while(1){
        
        if(test_and_set(&locked)==1){
            break;
        }
        else{
            //causes the calling thread 
            //to relinquish the CPU.
            //no busy waiting
            thread_yeild();
        }
    }
    
}

/*Unlock*/
void mutex_unlock(int*locked){
    
    *locked=0;
    //remove this process from queue
    wakeup();
}


/*Reader-Writer Lock using
pthread Mutex and pthread conditional 
Variable Multiple threads allowed to 
hold Lock when threads are reading 
and exclusive access is given when 
thread is writing*/

struct rwlock{
    
    int cnt;
    
    pthread_mutex_t lock;
    
    pthread_cond_t cond1;
};

/*Writer Lock*/
void writerLock(rwlock* writer){
    
    pthread_mutex_lock(&writer->lock);
    
    /*Won't be executing while (0)
    that is no one is holding lock*/
    while(writer->cnt){
        
        /*block on condition variable*/
        pthread_cond_wait(&writer->cond1, &writer->lock); 
    }
    
    writer->cnt = -1;
    
    pthread_mutex_unlock(&writer->lock);
}

/*Writer Unlock*/
void writeUnlock(rwlock* writer){
    
    pthread_mutex_lock(&writer->lock);
    
    writer->cnt = 0;
     
    /*unblocks threads blocked on condition
    variable*/
    pthread_cond_broadcast(&writer->cond1);
      
    pthread_mutex_unlock(&writer->lock);  

}

/*Reader Lock*/
void readerLock(rwlock* reader){
    
    pthread_mutex_lock(&reader->lock);
    
    /*Wait while writer is holding the lock*/
    while(reader->cnt < 0){
        
        pthread_cond_wait(&reader->cond1, &reader->lock);
        
    }
    
    reader->cond1++;
    
    pthread_mutex_unlock(&reader->lock);
}

/*Reader Unlock*/
void readerUnlock(rwlock* reader){
    
    pthread_mutex_lock(&reader->lock);
    
    reader->cond1--;
    
    /*unblocks writer thread blocked on condition
    variable*/
    if(reader->cond1==0){
        
        pthread_cond_signal(&reader->cond1);
    }
    
    
    pthread_mutex_unlock(&reader->lock);
}



