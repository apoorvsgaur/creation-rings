from user_score_calculate import github_score
github_venturesity_user_data = []
data = []
with open('github_venturesity_scores_1.txt') as f:
    [data.append(i.replace("\n","")) for i in f.readlines()]
    #data = f.read().replace("[","").replace("]","").replace(" ","").split(",")

final_list = []
for x in data:
    if x != "Invalid User":
        final_list.append(float(x))

final_list = sorted(final_list, reverse=True)
#print final_list
def get_relative_score(value):
     i = 0
     while (value < final_list[i]):
         i = i + 1

     return 1-(float(i)/len(final_list))

score = get_relative_score(github_score("hemanth"))
print score







# with open('github_scores.txt') as f:
#     [github_user_data.append(float(i.replace("\n",""))) for i in f.readlines()]
#
# final_list = sorted(github_user_data, reverse=True)
# #print final_list
#



# def get_relative_score(value):
#     i = 0
#     while (value < final_list[i]):
#         i = i + 1
#
#     return 1-(float(i)/1000)
#
# get_relative_score(27.25)


#[github_user_data.append(i) for i in data.replace(", ","\n")]
#print data.replace(", ","\n").sort()
