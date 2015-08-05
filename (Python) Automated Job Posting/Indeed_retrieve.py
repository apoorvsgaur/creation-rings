import mechanize
from bs4 import BeautifulSoup
import re
import urllib
import os
import mimetypes
import re

def indeed_retrieve():
  br = mechanize.Browser()
  br.set_handle_equiv(True)
  br.set_handle_gzip(True)
  br.set_handle_redirect(True)
  br.set_handle_referer(True)
  br.set_handle_robots(False)
  br.set_handle_refresh(mechanize._http.HTTPRefreshProcessor(), max_time=1)
  br.addheaders = [('User-agent', 'Firefox')]
  br.open('https://secure.indeed.com/account/login')
  br.select_form(name="loginform")
  br['email'] = 'saranya@venturesity.com'
  br['password'] = 'Venturesity@123'
  br.submit()
  response = br.open('https://employers.indeed.com/m#jobs')
  with open('response.html', 'w') as f:
      f.write(response.read())
  soup = response.read()
  print soup
  soup = BeautifulSoup(soup, "html.parser")
  print "1"
  a = soup.find_all('a', attrs={'data-element' : True})
  print a

indeed_retrieve()
