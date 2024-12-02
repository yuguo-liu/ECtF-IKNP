# ECtF-IKNP
Elliptic Curve to Field (ECtF) protocol based on IKNP

## Usage
1. Download emp-tool/emp-ot
2. Copy `ectf.cpp` to `emp-ot/test`
3. add the file to `CMakeLists.txt`
4. run it!

## Note
1. ECtF is used to implement the conversion from Elliptic Curve Points to Field share. That is, input two points $(x_1, y_1), (x_2,y_2)$ on the curve, output (get) $s_1,s_2$ such that $s_1+s_2=x_3, (x_1,y_1)+(x_2,y_2)=(x_3,y_3)$

2. `add2xor.cpp` is used to convert the arithmetic field additive shares to finite field additive shares