from selenium import webdriver
import time
import pyperclip


options = webdriver.Chromeoptions()
options.add_argument('headless')
driver = webdriver.Chrome('/usr/lib/chromium-browser/chromedriver', options=options)
driver.get('https://hisnet.handong.edu')
driver.switch_to.frame("MainFrame")
time.sleep(1)
print("Open hisnet ...")

tag_id = driver.find_element_by_name('id')
tag_pw = driver.find_element_by_name('password')

tag_id.click()
tag_id.send_keys('sy9010')
time.sleep(0.5)

tag_pw.click()
tag_pw.send_keys('kk1356790!')
time.sleep(0.5)

login_btn = driver.find_element_by_xpath("//*[@id='loginBoxBg']/table[2]/tbody/tr/td[5]/form/table/tbody/tr[3]/td/table/tbody/tr/td[2]/input")
login_btn.click()
time.sleep(1)

if driver.current_url == "https://hisnet.handong.edu/for_student/main.php":
    print("Login Succeed ...")
    login = 1
else:
    try:
        result = driver.switch_to.alert
        # alert 창 내용 출력
        result.accept()
        result.dismiss()
        login = 0

    except:
        pass
    print("로그인 실패")
    driver.quit()

class_info = driver.find_element_by_xpath('//*[@id="div_TopmenuBg"]/table/tbody/tr[2]/td[2]/div/a[1]/img')
class_info.click()
pre_register = driver.find_element_by_xpath('/html/body/table[1]/tbody/tr[2]/td/table/tbody/tr/td[1]/table/tbody/tr[2]/td/table/tbody/tr[4]/td/div/table/tbody/tr[3]/td/div/a')
pre_register.click()

f = open("timetable.txt", 'r')
lines = f.readlines()
f.close()

f = open("pre_register_num.txt", 'w')

print('Getting information ...')
for line in lines:
    info = line.split('-')
    info[1] = info[1].strip()
    # print("과목코드:"+info[0]+", "+info[1]+"분반")
    subject_code_search_box = driver.find_element_by_xpath('//*[@id="att_list1"]/tbody/tr[1]/td/input[3]')
    subject_code_search_box.click()
    subject_code_search_box.clear()
    subject_code_search_box.send_keys(info[0])
    button_ok = driver.find_element_by_xpath('//*[@id="att_list1"]/tbody/tr[2]/td/a/img')
    button_ok.click()
    time.sleep(1)
    pre_register_total = driver.find_element_by_xpath('//*[@id="att_list"]/tbody/tr[%s]/td[9]/font' % (str(int(info[1])+1)) ).get_attribute('innerHTML')
    register_num = driver.find_element_by_xpath('//*[@id="att_list"]/tbody/tr[%s]/td[11]/font' % (str(int(info[1])+1) )).get_attribute('innerHTML')
    # print("수강 가능 인원 "+str(register_num)+"명, 현재 예비수강신청 인원 "+str(pre_register_total)+"명")
    f.write(info[0]+" "+info[1]+" "+pre_register_total+" "+register_num+"\n")

f.close()
print('Succeed to get information.')
driver.quit()
