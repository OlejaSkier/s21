mv door_management_fi door_management_files
mkdir door_configuration
for filename in *.conf; do
	mv $filename door_configuration
done
mkdir door_map
mv door_map_1.1 door_map
mkdir door_logs
for filename in *.log; do
	mv $filename door_logs
done
