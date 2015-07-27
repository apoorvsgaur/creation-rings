#done
import mechanize
import cookielib

def trovitjob(form):
  return form.attrs.get('id', None) == 'loginform'

def step1(form):
  return form.attrs.get('id', None) == 'step1'

def step2(form):
  return form.attrs.get('id', None) == 'step2'

def trovit(Job_Post): #
  br = mechanize.Browser()
  br.set_handle_equiv(True)
  br.set_handle_gzip(True)
  br.set_handle_redirect(True)
  br.set_handle_referer(True)
  br.set_handle_robots(False)
  cj = cookielib.LWPCookieJar()
  br.set_cookiejar(cj)
  br.set_handle_refresh(mechanize._http.HTTPRefreshProcessor(), max_time=1)
  br.addheaders = [('User-agent', 'Chrome')]
  br.open('http://jobs.trovit.co.in/index.php/cod.mytrovit_login_frm')
  br.select_form(predicate=trovitjob)
  br['email'] = Job_Post.login_id
  br['pwd'] = Job_Post.password
  br.submit()
  while(True):
    try:
       br.open('http://jobs.trovit.co.in/recruitment')
       break
    except:
       pass
  br.select_form(predicate=step1)
  br['email'] = Job_Post.login_id
  br['title'] = Job_Post.company_name + " is looking for " + Job_Post.job_title + " in " + Job_Post.city
  br['content'] = Job_Post.job_description
  br['location'] = Job_Post.city
  br.select_form(predicate=step2)
  br['salary'] = str(((int(Job_Post.min_salary) + int(Job_Post.max_salary))/2)/64)
  br['contract'] = ['1744']
  br['workingHours'] = ['1752']
  if (int(Job_Post.min_years) == 0):
      br['experience'] = ['4522']
  elif (int(Job_Post.min_years) > 0 and int(Job_Post.min_years) < 3):
      br['experience'] = ['4524']
  elif (int(Job_Post.min_years) > 2 and int(Job_Post.min_years) < 5):
      br['experience'] = ['4526']
  elif (int(Job_Post.min_years) > 4 and int(Job_Post.min_years) < 7):
      br['experience'] = ['4528']
  else:
      br['experience'] = ['4530']

  if (int(Job_Post.no_of_vacancies) > 9):
     br['vacants'] = ['10']
  else:
     br['vacants'] = [Job_Post.no_of_vacancies]
  br.select_form(predicate=step1)
  br.submit()
  #with open ("trovit_result_page.txt", 'w') as f:
   #   f.write(response.read())
