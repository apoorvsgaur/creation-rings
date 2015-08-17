import csv

with open('ranked_list.txt') as f:
    data = f.readlines()

writer = csv.writer(open('venturesity_list_1.csv', 'wb'))
for x in data:
    data = x.replace("(","").replace(")","").replace("\n","").replace("'","").replace(" ","").split(",")
    writer.writerow([data[0], data[1]])
