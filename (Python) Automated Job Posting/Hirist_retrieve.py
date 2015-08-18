import mechanize
from bs4 import BeautifulSoup
import re
import urllib
import os
import mimetypes
import re

def hirist_retrieve():
  br = mechanize.Browser()
  br.set_handle_equiv(True)
  br.set_handle_gzip(True)
  br.set_handle_redirect(True)
  br.set_handle_referer(True)
  br.set_handle_robots(False)
  br.set_handle_refresh(mechanize._http.HTTPRefreshProcessor(), max_time=1)
  br.addheaders = [('User-agent', 'Chrome')]
  br.open('http://www.hirist.com/recruiter/jobpost.php')
  br.select_form(name="recruiterRegLogin")
  br['email'] = 'saranya@venturesity.com'
  br['password'] = 'Venturesity@123'
  br.submit()
  response = br.open('http://www.hirist.com/recruiter/recruiter.php')
  soup = response.read()
  soup = BeautifulSoup(soup, "html.parser")
  j = 1
  k = 0
  for link in soup.find_all('a', title="Total Apply"):
      if k < j:
         names_list = []
         response = br.open(link.get('href'))
         soup = BeautifulSoup(response, "html.parser")
         name_of_job = soup.find_all('h2', {"class":"hidden-xs"})[0].text
         if not os.path.exists(os.path.join(os.path.expanduser("~/Desktop/Job Postings/Hirist/" + name_of_job.strip().replace("/","_")))):
             os.makedirs(os.path.join(os.path.expanduser("~/Desktop/Job Postings/Hirist/" + name_of_job.strip().replace("/","_"))))
         for names in soup.find_all('p', {"class" : "smallviewtext"}):
             string = str(names).split("<br/>")[0].split()
             names_list.append(' '.join(string[2:]))
         print names_list
         i = 0
         for link in soup.find_all('a'):
             if 'resumedownload' in link.get('href'):
             #print link.get('href')
                  filename, headers = br.retrieve(link.get('href'))
                  content_type = headers.get('Content-Type', '').split(";")[0]
                  extension = mimetypes.guess_extension(content_type)
                  if not os.path.exists(os.path.expanduser("~/Desktop/Job Postings/Hirist/" + name_of_job.strip().replace("/","_") + "/" + names_list[i] + extension)):
                     br.retrieve(link.get('href'), os.path.expanduser("~/Desktop/Job Postings/Hirist/" + name_of_job.strip().replace("/","_") + "/" + names_list[i] + extension))[0]
                  i = i + 1
          k = k + 1
                 #print extension

                 #with open('resume.txt', 'w') as f:
                    #   f.write(response.read())
      else:
              break
