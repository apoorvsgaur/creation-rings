import mechanize
from bs4 import BeautifulSoup
import re
import urllib
import os

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
  br['email'] = 'apoorv@venturesity.com'
  br['password'] = 'venturesity@123'
  br.submit()
  response = br.open('http://www.hirist.com/recruiter/recruiter.php')
  soup = response.read()
  soup = BeautifulSoup(soup, "html.parser")
  for link in soup.find_all('a', title="Total Apply"):
     response = br.open(link.get('href'))
     soup = BeautifulSoup(response, "html.parser")
     i = 0
     for link in soup.find_all('a'):
         if 'resumedownload' in link.get('href'):
             print link.get('href')
             i = i + 1
             response = br.open(link.get('href'))
             with open('resume.txt', 'w') as f:
                 f.write(response.read())
                 x++
hirist_retrieve()
