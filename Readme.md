# 使用说明

## 单架无人机调试模式:  
安装所有包后,运行:

`source ./devel/setup.bash`  
`roslaunch hector_quadrotor_demo flat.launch`  

-----

## 多架无人机调试模式:
安装好所有包之后,运行:

`source ./devel/setup.bash`  
`roslaunch hector_quadrotor_demo flat.launch`

--------------------
# 更新履历

## 2017.1.7

- 加入一键起飞功能.  
- 后面要修改起飞的机制.在起飞的时候,关掉控制器.  
- 上面的功能已经在下午有了初步的效果,但还是要完善呢,看当天的commit就好了.

### 值得完善的地方:
 0. 起飞使用最大油门来起飞
 0. 判断条件达到好像还是不太好
