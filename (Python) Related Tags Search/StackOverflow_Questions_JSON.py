__author__ = 'Apoorv'

import requests
import json
import time


pages = [927, 928, 929, 930, 931, 932, 933, 934, 935, 936, 937, 938, 939, 940, 941, 942, 943, 944, 945, 946, 947, 948, 949, 950, 951, 952, 953, 954, 955, 956, 957, 958, 959, 960, 961, 962, 963, 964, 965, 966, 967, 968, 969, 970, 971, 972, 973, 974, 975, 976, 977, 978, 979, 980, 981, 982, 983, 984, 985, 986, 987, 988, 989, 990, 991, 992, 993, 994, 995, 996, 997, 998, 999, 1000]

for x in pages:
    print x
    start_time = time.time()
    url = "https://api.stackexchange.com/2.2/questions?page=" + str(x) + "&pagesize=100&order=desc&sort=activity&site=stackoverflow"
    fp = open('Pages/page_' + ("%04d" % x) + '.txt', 'w')
    # data = json.loads(requests.get(url).text)
    while(True):
        try:
            data = requests.get(url).text
            print len(data)
            if (len(data) == 141):
               time.sleep(15)
               continue
            else:
                break
        except Exception as e:
            print e

    fp.write(data.encode('utf8'))
    fp.close()
    print "Speed : " + str(time.time() - start_time)
    # for y in range(0,100):
    #     fp.write(data['items'][x]['tags'])
    #     print (data['items'][x]['question_id'])

