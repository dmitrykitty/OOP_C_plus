read value
if (( value > 0 )); then
  echo "${value} is positive"
elif (( value == 0 )); then
  echo "your number is 0"
else
  echo "${value} is negative"
fi #zakonczenie if


echo "Enter command:"
read command

case "${command}" in
clean)# case 1
  echo "Clean is invoked"
  ;; #koniec tego case
build)# case 2
  echo "Build is invoked"
  ;;
*) #default case
  echo "Program is not supported"
  exit 2
  ;;
esac #end of switch case