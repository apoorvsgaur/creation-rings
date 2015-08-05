import csv
from user_score_calculate import github_score
from get_user_score import get_relative_score
import operator

venturesity_user_list = []
venturesity_score_dict = {}
with open('github_urls_cleaned.csv', 'rb') as csvfile:
    github_urls = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for handle in github_urls:
       if (len(handle) != 0):
            venturesity_user_list.append(handle[0].split("/")[-1])
print (len(venturesity_user_list))
i = 1
for x in venturesity_user_list:
    with open('number_of_API_calls.txt', 'w') as f:
        f.write(str(i))
    score = github_score(x)
    if type(score) == type(0.5):
        venturesity_score_dict[x] = get_relative_score(score)
    else:
        venturesity_score_dict[x] = score
    i = i + 1

venturesity_score_dict = sorted(venturesity_score_dict.items(), key=operator.itemgetter(1))
venturesity_score_dict = dict(venturesity_score_dict)
print venturesity_score_dict
f = open('github_results.txt', 'w')
for keys, value in venturesity_score_dict.items():
    f.write("Github Handle: " + str(keys) + " Score: " + str(value) + '\n')
f.close()
