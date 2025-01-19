# Chicken Shooter
In this project, i learn about create a game only by C and C++
# Table of Content
- [Init Game](#Init Game)
- [Drawing Graphic](#Drawing Graphic)
- [Input, Movement and Time](#Input, Movement and Time)
## Init Game

## Drawing Graphic

## Input, Moment and Time
Init 4 Orientation Key to make an object move
When you press a button, a single frame is generated
A Button has 2 state: Press and Release
from the begining, if we do nothing with keyboard, the status of buttons.changed = false so it not release state, when we press, the changed variable change to true so that button is used.
when the button is used, we interested in which state button are, press or release.
So we need a struct like
