
# Chicken Shooter

In this project, i learn about create a game only by C and C++

# Table of Content

- [Init Game](#Init-Game)

- [Drawing Graphic](#Drawing-Graphic)

- [Input, Movement and Time](#Input,-Movement-and-Time)

## Init Game

  

## Drawing Graphic

  

## Input, Moment and Time

 1. Input and Movement
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Init 4 Orientation Key to make an object move. When you press a button, a single frame is generated. A button has 2 state: Press and Release. From the begining, if we do nothing with keyboard, the status of `buttons.changed = false` so it not release state, when we pressing, `button.changed = true` so that button is used. When the button is used, we interested in which state button are, press or release. So we need a struct like 
```cpp
	struct Button_State{
		bool is_down;
		bool changed;
	};
```
2. Time
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Nomally, if we want to change position of an object, we often use `pos += speed`. But this way, when we play on another resolution, the speed dose not match any more (larger screen, slower speed), so we use `pos += speed * frame_per_sec` to calculate position.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`frame_per_sec` or FPS speed of farme per second which mean that in one second, how many farme is display on your screen.

|  FPS|Time(s)  |Time (ms)|
|--|--|--|
| 60 |0.01666s  |16.66ms|
|30|0.03333s|33.33ms
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;

