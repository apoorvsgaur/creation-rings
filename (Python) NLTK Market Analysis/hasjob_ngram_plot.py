__author__ = 'Apoorv'
import nltk
import operator
import urllib2
from bs4 import BeautifulSoup
import time

with open('final.txt') as f:
    data = f.read().lower()

data = data.replace('/', ' ')
#data = data.replace('-', ' ')

#Generate frequency of all words
data = data.decode("utf8")
tokens = nltk.word_tokenize(data)
ngram_res = nltk.ngrams(tokens, 1)
frequency = nltk.FreqDist(ngram_res)

sorted_freq = sorted(frequency.items(), key=operator.itemgetter(1))
sorted_freq.reverse()
with open('final_result.txt','w') as f:
   for x in sorted_freq:
      try:
        f.write(unicode(x[0][0]) + '\t' + unicode(x[1]) + '\n')
      except:
          pass

with open('tags_stackoverflow.txt') as f:
    tags = f.read().split('\n')

final = open('popular_tags.csv','w')
y = 0
for x in sorted_freq:
    if x[0][0] in tags:
        #print('yes\t\t' + x[0][0])
        if((y % 4) == 0):
           final.write(unicode(x[0][0]) + ',' + unicode(x[1]))
        elif((y-1)%4 == 0):
             final.write(','+ unicode(x[0][0]) + ',' + unicode(x[1]) + '\n')
        else:
           final.write(','+ unicode(x[0][0]) + ',' + unicode(x[1]) + ',')
        y+=1
    else:
       pass
       # print('no\t\t' + x[0][0])
       # time.sleep(0.5)
final.close()





