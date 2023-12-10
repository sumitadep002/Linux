
# Read the number of integers
read n

# Initialize variables
sum=0

# Loop to read integers and calculate the sum
for ((i=0; i<n; i++))
do
    read num
    sum=$((sum + num))
done

# Calculate the average
average=$(echo "scale=3; $sum / $n" | bc)

# Display the average
if [ $average -eq 0 ]
then
echo "0.000"
else
echo $average
fi

