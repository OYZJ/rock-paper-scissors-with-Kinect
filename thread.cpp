
#include "thread.h"
#include <iostream>
Thread::Thread()
{

    std::cout<<"init "<<std::endl;
}
void Thread::run()
{

    CBodyBasics myKinect;
    HRESULT hr = myKinect.InitializeDefaultSensor();
    if (SUCCEEDED(hr)){
      while (1){
            myKinect.Update();
            Q_EMIT oySignal(myKinect.GetGesture());
        }
    }
    else{
        std::cout << "kinect initialization failed!" << std::endl;
        system("pause");
    }

}
