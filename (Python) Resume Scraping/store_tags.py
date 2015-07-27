__author__ = 'Apoorv'

from conversion_to_text import convert_pdf_to_txt, document_to_text
import os
from os import walk
import nltk
import time

strings = []
path = "C:\Venturesity\Python_Scripts\Resume_Scraping\Resumes"
path_tags = "C:\Venturesity\Python_Scripts\Resume_Scraping"
for (dirpath, dirnames, filenames) in walk(path):
    strings.extend(filenames)
    break

with open("tech-tags-sorted.txt") as f:
    tags_list = f.read().replace("\t", "")
    tags_list = tags_list.split("\n")

def dict_list(data):
    data = data.decode("utf8")
    tokens = nltk.word_tokenize(data)
    ngram_res = nltk.ngrams(tokens, 1)
    return ngram_res

count = 0
for x in strings:
    start = time.time()
    count+=1
    print(x)
    print(count)
    if x[-4:] == ".doc":
        tags = []
        data = document_to_text(x,path+"\\"+x).lower()
        tokens = dict_list(data)
        f = open(path_tags + "\Resume Tags\\" + x[:-4] + ".txt", 'w')
        for x in tokens:
          if x[0].encode('utf8').lower() in tags_list:
              tags.append(x[0].encode('utf8'))
        tags = set(list(set(tags)))
        f.write(','.join(sorted(tags)))
        f.close()
    elif x[-5:] == ".docx":
        tags = []
        data = document_to_text(x,path+"\\"+x).lower()
        tokens = dict_list(data)
        f = open(path_tags + "\Resume Tags\\" + x[:-5] + ".txt", 'w')
        for x in tokens:
          if x[0].encode('utf8').lower() in tags_list:
              tags.append(x[0].encode('utf8'))
        tags = set(list(set(tags)))
        f.write(','.join(sorted(tags)))
        f.close()
    elif x[-4:] == ".pdf":
        tags = []
        data = document_to_text(x,path+"\\"+x).lower()
        tokens = dict_list(data)
        f = open(path_tags + "\Resume Tags\\" + x[:-4] + ".txt", 'w')
        for x in tokens:
          if x[0].encode('utf8').lower() in tags_list:
              tags.append(x[0].encode('utf8'))
        tags = set(list(set(tags)))
        f.write(','.join(sorted(tags)))
        f.close()
    # elif x[-4:] == ".odt":
    #     tags = []
    #     data = document_to_text(x,path+"\\"+x).lower()
    #     tokens = dict_list(data)
    #     f = open(path_tags + "\Resume Tags\\" + x[:-5] + ".txt", 'w')
    #     for x in tokens:
    #       if x[0].encode('utf8').lower() in tags_list:
    #           tags.append(x[0].encode('utf8'))
    #     tags = set(list(set(tags)))
    #     f.write(','.join(sorted(tags)))
    #     f.close()

    print("Time per resume:" + str(time.time()-start))
