import mechanize
import cookielib

def newjob(form):
  return form.attrs.get('id', None) == 'newjob'

def login_auth(form):
  return form.attrs.get('id', None) == 'form-openid'

def hasjob_co(Job_Post): #Job_Post
   br = mechanize.Browser()
   br.set_handle_equiv(True)
   br.set_handle_gzip(True)
   br.set_handle_redirect(True)
   br.set_handle_referer(True)
   br.set_handle_robots(False)

   #br.set_debug_http(True)
   #br.set_debug_responses(True)
   # Cookie Jar
   cj = cookielib.LWPCookieJar()
   br.set_cookiejar(cj)

   br.set_handle_refresh(mechanize._http.HTTPRefreshProcessor(), max_time=1)
   br.addheaders = [('User-agent', 'Chrome')]
   br.open('https://auth.hasgeek.com/login')
   br.select_form(nr=1)
   br['username'] = Job_Post.login_id
   br['password'] = Job_Post.password
   br.submit()
   br.open('https://hasjob.co/new')
   br.select_form(predicate=newjob)
   br['job_headline'] = Job_Post.job_title
   br['job_type'] = ['1']
   br['job_category'] = [Job_Post.category_1]
   br['job_location'] = Job_Post.city
   string = Job_Post.job_description.replace("\n","<br>")
   br['job_description'] = string
   # except:
   #     try:
   #         br['job_description'] = string.decode('utf-8')
   #     except:
   #         br['job_description'] = string.encode('utf-8')
   br['job_pay_type'] = ['2']
   br['job_pay_currency'] = ['INR']
   br['job_pay_cash_min'] = Job_Post.min_salary
   br['job_pay_cash_max'] = Job_Post.max_salary
   br['job_how_to_apply'] = 'Send resume to specified email.'
   br['company_name'] = Job_Post.company_name
   br['company_url'] = Job_Post.company_website
   br['poster_email'] = Job_Post.login_id
   br.submit()
   br.select_form(nr=1)
   br.submit()
   br.select_form(nr=1)
   br.find_control(type="checkbox").items[0].selected=True
   br.submit()
   #with open ("hasjob_result_page.txt", 'w') as f:
#        f.write(response.read())
