ps -a
echo find and write pid ai_door_control.sh
read pidnumber
kill $pidnumber
