from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
import time

def quickr(Job_Post):
    driver = webdriver.Firefox()
    #logging in
    driver.get("http://www.quikr.com/bye")
    element = driver.find_element_by_id("loginemail")
    element.send_keys(Job_Post.login_id)
    element = driver.find_element_by_id("PasswordId")
    element.send_keys(Job_Post.password)
    driver.find_element_by_id("SubmitBtn").click()
    time.sleep(5)
    #Post an ad
    driver.get("http://www.quikr.com/post-classifieds-ads/?postadcategoryid=18230061")
    element = driver.find_element_by_id("title")
    element.send_keys("Looking for " + Job_Post.job_title)
    element = driver.find_element_by_id("Company_Name")
    element.send_keys(Job_Post.company_name)
    select_box = Select(driver.find_element_by_id("Role_newpap"))
    time.sleep(1)
    #Drop-down Menu
    select_box.select_by_value(Job_Post.category_3)
    select_box = Select(driver.find_element_by_id("Education_newpap"))
    time.sleep(1)
    select_box.select_by_value("Graduate")
    select_box = Select(driver.find_element_by_id("Experience_newpap"))
    time.sleep(1)
    if(int(Job_Post.min_years) < 1):
       select_box.select_by_value("Less than 1 yr")
    elif (int(Job_Post.min_years) > 0 and int(Job_Post.min_years) < 3):
       select_box.select_by_value("1 - 3 yrs")
    elif (int(Job_Post.min_years) > 2 and int(Job_Post.min_years) < 5):
       select_box.select_by_value("3 - 5 yrs")
    elif (int(Job_Post.min_years) > 4 and int(Job_Post.min_years) < 8):
       select_box.select_by_value("5 - 8 yrs")
    elif (int(Job_Post.min_years) > 7 and int(Job_Post.min_years) < 10):
        select_box.select_by_value("8 - 10 yrs")
    elif (int(Job_Post.min_years) > 9 and int(Job_Post.min_years) < 15):
        select_box.select_by_value("10 - 15 yrs")
    else:
        select_box.select_by_value("More Than 15 yrs")
    #select_box = Select(driver.find_element_by_id("cityNewSelectBox2"))
    driver.find_element_by_id("cityNewSelectBox2").click()
    element = driver.find_element_by_id("searchcity55")
    element.send_keys(Job_Post.city)
    time.sleep(2)
    driver.find_element_by_css_selector("ul li[id='green_dhtml_content55_" + Job_Post.city + "'] a").click()
    driver.find_element_by_id("singleSelLoc").click()
    time.sleep(2)
    driver.find_element_by_css_selector("div[id='customSingleSelLoc'] span").click()
    try:
      driver.find_element_by_css_selector("div[class='AudioDescr-GrayBox text-descr-box']").click()
    except:
        pass
    time.sleep(1)
    element = driver.find_element_by_id("description1")
    element.send_keys(Job_Post.job_description.decode('utf-8'))
    element = driver.find_element_by_id("contactName")
    element.send_keys(Job_Post.name)
    #element = driver.find_element_by_id("emailid")
    #element.send_keys("apoorv@venturesity.com")
    element = driver.find_element_by_id("mobile")
    element.send_keys(Job_Post.mobile_no)
    driver.find_element_by_id("alertpostad").click()
    driver.find_element_by_class_name("postbtn").click()
    #time.sleep(1)
    #element.send_keys(Keys.TAB)
    #time.sleep(1)
    #element.send_keys(Keys.RETURN)
    # driver.execute_script('document.getElementById("green_dhtml55").setAttribute("class", "main_sugcitydiv");')
    # time.sleep(2)
    # driver.find_element_by_id("selcity-label55").click()
    # time.sleep(2)
    # element = driver.find_element_by_id("searchcity55")
    # element.send_keys("Bangalore")
    # time.sleep(2)
    # driver.find_element_by_id('green_dhtml_content55_Bangalore').click()
    #
