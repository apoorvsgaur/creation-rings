import mechanize

def hirist_post(Job_Post): #Job_Post
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
  br['email'] = Job_Post.login_id
  br['password'] = Job_Post.password
  br.submit()
  br.select_form(name="jobPostFrm")
  br['subject'] = Job_Post.job_title
  br['otherslocation'] = Job_Post.city
  br['category'] = [Job_Post.category_2]
  br['minexp'] = [Job_Post.min_years]
  br['maxexp'] = [Job_Post.max_years]
  br['introtext'] = Job_Post.job_description
  br.submit()
#  with open ("hirist_result_page.txt", 'w') as f:
#        f.write(response.read())
