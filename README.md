# Application to account for people's entries

**PROJECT:** 

In this project, an application was developed that, using a camera, accounts for the number of people who pass, for example, through a door, through facial recognition. In addition, it was also necessary to have the functionality to be able to limit the detection to only a specific region. The application was implemented in C ++, using Qt, as a graphical interface, and the OpenCV library to read images from the camera and face detection, Video Capture and Haar Cascades, respectively. A thread was also used to optimize the entire process.

**FEATURES:** 

* Collection of images in real time from a camera;
* Face detection, even in a single frame;
* Definition of a region of interest;
* Accounting for the number of people.

**FILES:** 
* [aplicacao.pro](https://github.com/MiguelCastro3/Application-for-manual-segmentation/blob/master/aplicacao.pro) - application project file.
* [camera.h](https://github.com/MiguelCastro3/Application-to-account-for-people-s-entries/blob/master/camera.h) and [camera.cpp](https://github.com/MiguelCastro3/Application-to-account-for-people-s-entries/blob/master/camera.cpp) - class camera with the code for the back-end of the developed application and connection with the thread class and mouse_press_event class. It has the function of displaying images, received from the camera, and the results obtained from the thread class.
* [camera.ui](https://github.com/MiguelCastro3/Application-to-account-for-people-s-entries/blob/master/camera.ui) - interface implemented for the front-end of the final application.
* [thread.h](https://github.com/MiguelCastro3/Application-to-account-for-people-s-entries/blob/master/thread.h) and [thread.cpp](https://github.com/MiguelCastro3/Application-to-account-for-people-s-entries/blob/master/thread.cpp) - process and analyze the images. Using the Haar Cascades class, it detects faces in each of the frames received.
* [mouse_press_event.h](https://github.com/MiguelCastro3/Application-to-account-for-people-s-entries/blob/master/mouse_press_event.h) and [mouse_press_event.cpp](https://github.com/MiguelCastro3/Application-to-account-for-people-s-entries/blob/master/mouse_press_event.cpp) - records the points where the mouse clicked to allow the definition of the region of interest.


**RESULTS:** 
The images on the left are the real-time images captured by the camera while the images on the right are snapshoots of when a face detection occurs.

Last detection performed - green square:
![1](https://user-images.githubusercontent.com/66881028/85320486-0bea2600-b4bb-11ea-9574-d187ec2b1cd5.png)

Definition of a region of interest - red square:
![2](https://user-images.githubusercontent.com/66881028/85320489-0c82bc80-b4bb-11ea-890f-d72bb0834f45.png)

Detection performed after defining the region of interest - green square:
![3](https://user-images.githubusercontent.com/66881028/85320491-0d1b5300-b4bb-11ea-9188-c8f462505f26.png)
