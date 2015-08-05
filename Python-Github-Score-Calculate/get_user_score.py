github_user_data = []
with open('github_scores.txt') as f:
    [github_user_data.append(float(i.replace("\n",""))) for i in f.readlines()]

final_list = sorted(github_user_data, reverse=True)
#print final_list
def get_relative_score(value):
    i = 0
    while (value < final_list[i]):
        i = i + 1

    return 1-(float(i)/1000)

get_relative_score(27.25)
#[github_user_data.append(i) for i in data.replace(", ","\n")]
#print data.replace(", ","\n").sort()
