import numpy as np
from numpy import matrix
from numpy.linalg import inv
from sklearn.cluster import KMeans
from user_score_calculate import github_score

# with open('github_bangalore_score.txt') as f:
#     scores = f.readlines()
# list_of_scores = []
# for x in scores:
#     list = []
#     str_value_list = x.split(":")[1].strip().replace("[","").replace("]","").replace(" ","").split(",")
#     for x in str_value_list:
#         list.append(float(x))
#     list_of_scores.append(list)
with open('github_bangalore_scores_1.txt') as f:
    data = f.read().replace("[[","[").replace("]]","]").replace(" ","").replace("'InvalidUser'","").replace("]\n","").split("],")

str_list = []
for x in data:
    str_list.append(x.replace("[","").split(","))

final_list = []
for x in str_list:
    list = []
    for y in x:
        if y != '':
           list.append(int(y))
    final_list.append(list)

matrix = np.array(final_list)
#print matrix

kmeans = KMeans(n_clusters=23)
kmeans.fit(matrix)
labels = kmeans.labels_


for label_value in range((len(set(labels)))):
    labels_list = []
    for i in range(len(matrix)):
        if (labels[i] == label_value):
            labels_list.append(matrix[i])

    list_100s = []
    for x in range(len(labels_list)):
        list_100s.append([100])

    simulated_results = np.array(list_100s)
    users_matrix = np.array(labels_list)
    #print (simulated_results.shape)
    #print (users_matrix.shape4)
    #print inv(labels_list)*simulated_results
    try:
        least_squares = inv(np.transpose(users_matrix).dot(users_matrix)).dot(np.transpose(users_matrix)).dot(simulated_results)
        if ((least_squares > 0).all()):
           print (label_value, least_squares, users_matrix)
    except:
        pass
        #print "Singular matrix"
    #print type(users_matrix)
    #print type(simulated_results)
#matrix_labels = np.array(labels_list)

#print inv(np.transpose(a)*a)*np.transpose(a)*b



#with open('github_bangalore_users.txt') as f:
#     data = f.read().splitlines()

#total_list = np.array([[0,0,0,0,0]])
#count = 1
#file = open("github_bangalore_score.txt","w")
#break_var = 0
#for username in data:
#    with open("number_users_done.txt", 'w') as f:
#        f.write(str(count))
#    count = count + 1
#    score = github_score(username)
#    file.write(username + ": " + str(score) + "\n")
#    new_list = np.array([score])
#    total_list = np.append(total_list, new_list, 0)
#    break_var = break_var + 1
#    if (break_var > 150):
#        break
#file.close()

#kmeans = KMeans(n_clusters=9)
#kmeans.fit(total_list)
#labels = kmeans.labels_

#f = open("clusters_150_9.txt",'w')
#for i in range(150):
#    f.write("User Score: " + str(total_list[i]) + "Label: " + str(labels[i]) + "\n")
#f.close()


# for x in ideal_users:
#     matrix_scores.append(github_score(x))
#     with open('number_users_done.txt','w') as f:
#         f.write(str(i))
#     i = i + 1
#
# print matrix_scores
