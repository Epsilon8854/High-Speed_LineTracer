# High-Speed_LineTracer

## Overview
1.5~2.4m/s정도의 속도로 달리는 라인트레이서입니다. 적외선 센서를 이용하여 검/흰을 판단하며 Cortexm과 Stepping모터를 활용하여 구현하였습니다.
다음과 같은 기술들이 사용되었습니다.

This is a Linetracer that runs at a speed of 1.5-2.4m/s. It is developed using **Cortex M** and **Stepping motors** .It also uses infrared sensors to recognize black and white.
The following technologies were used
- ### High Speed Filter
  To remove the dc component which caused by natural light
- ### PID controller
  To Control the speed & steer

![]()

## Video
[![LineTracer](https://img.youtube.com/vi/DuSCqCeqaWY/0.jpg)](https://youtu.be/DuSCqCeqaWY)
## H/W Specification
- Power: 48V, 460mAh, 15~30C
- Motor: KH42J
- Motor driver: SLA7026
- MCU: stm32f103ZET


![](https://imgur.com/5YUE6kI.jpg)