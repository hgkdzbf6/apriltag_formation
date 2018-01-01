cd ./aprilslam && git add . && git commit -m "PC upload" && git push origin +master
cd ..
cd ./hector_quadrotor && git add . && git commit -m "PC upload" && git push origin kinetic-devel
cd ..
cd ./hector_localization && git add . && git commit -m "PC upload" && git push origin catkin
cd ..
cd ./hector_gazebo && git add . && git commit -m "PC upload" && git push origin +master
cd ..
cd ./hector_models && git add . && git commit -m "PC upload" && git push origin  kinetic-devel
cd  ..
git add . && git commit -m "PC upload" && git push origin +master

