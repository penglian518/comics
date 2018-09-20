#!/Users/p6n/tools/anaconda2/bin/python

import urllib2, os, time
import unicodedata
import codecs
from bs4 import BeautifulSoup
from selenium import webdriver
from copy import deepcopy

class fetcher:
    def __init__(self):
        return

    def fetcher(self, url, pub_year):
        fcon = []
        pubs, dois = self.pub_fetcher(url, pub_year)

        for p, d in zip(pubs, dois):
            line = self.format_pub_html(p, d)
            fcon.append(line)

        fcon_html = '\n'.join(fcon)

        return fcon_html



    def pub_fetcher(self, url, pub_year):
        '''
        only works for google scholar!
        '''
        soup = BeautifulSoup(urllib2.urlopen(url), features="lxml")
        records = soup.find_all('tr', attrs={'class': 'gsc_a_tr'})

        pubs = []
        for tr in records:
            year = tr.find('td', attrs={'class': 'gsc_a_y'}).text
            if year in [str(pub_year)]:
                pub_title = tr.find('a').text
                pub_author_journal = tr.find_all('div', attrs={'class': 'gs_gray'})
                pub_author = pub_author_journal[0].text
                pub_journal = pub_author_journal[1].text

                pub_data_href = tr.find('a').attrs['data-href']

                # format
                try:
                    pub_author_list = self.format_author_names(pub_author)
                except:
                    pub_author_list = []

                pub_author_str = ', '.join(pub_author_list)
                pub_author_formated = '%s (%s)' % (pub_author_str, pub_year)
                pub_journal_formated = pub_journal.replace(pub_year, '').strip().strip(',')
                pub_data_href_formated = '%s#d=gs_md_cita-d&p=&u=%s' % (url, urllib2.quote(pub_data_href.replace('amp;', '')))

                pubs.append([pub_author_formated, pub_title, pub_journal_formated, pub_data_href_formated])

        # get the doi link address
        # open the web browser
        driver = webdriver.Chrome(executable_path="/Users/p6n/tools/bin/chromedriver")
        dois = []
        pubs_new = []
        for pub in pubs:
            print('Working on: %s ...\n' % pub[1])
            doi = ''
            try:
                data_href = pub[3]
                driver.get(data_href)
                time.sleep(1)
                soup = BeautifulSoup(driver.page_source, features="lxml")
                soup_author = deepcopy(soup)
                time.sleep(1)
                a = soup.find_all('a', attrs={'class': 'gsc_vcd_title_link'})
                print (a)
                doi = a[0].attrs['href']

                #update the authors
                pub_author = self.get_authors(soup_author)
                # format
                try:
                    pub_author_list = self.format_author_names(pub_author)
                except:
                    pub_author_list = []

                pub_author_str = ', '.join(pub_author_list)
                pub_author_formated = '%s (%s)' % (pub_author_str, pub_year)

                pubs_new.append([pub_author_formated, pub[1], pub[2], pub[3]])

            except Exception as e:
                print('Cannot find doi for %s' % pub[1])
                print('The error is: %s' % e)
                doi = ''

            dois.append(doi)

        return pubs_new, dois

    def get_authors(self, soup):
        pub_author = ''
        divs = soup.find_all('div', attrs={'class': 'gs_scl'})
        for d in divs:
            try:
                field = d.find('div', attrs={'class': 'gsc_vcd_field'}).text
                value = d.find('div', attrs={'class': 'gsc_vcd_value'}).text
            except:
                pass

            if field in ['Authors']:
                pub_author = value
        return pub_author

    def format_author_names(self, pub_author):
        author_list_new = []
        author_list = [i.strip() for i in pub_author.split(',')]

        for i in author_list:
            last = i.split()[-1]
            first_list = i.split()[:-1]
            first = ''
            for l in first_list:
                first += l[0]
            new = '%s %s' % (last, first)
            print (new)
            author_list_new.append(new)

        return author_list_new


    def format_pub_html(self, pub, doi):

        Names = pub[0]
        Title = pub[1]
        Journal = pub[2]

        if doi in ['']:
            outformat = '''<div>
<p class="body"><span style="font-family: verdana, geneva, sans-serif; font-size: 12pt;">%s</span><br /><span style="font-family: verdana, geneva, sans-serif; font-size: 12pt;"> <b>%s</b></span><br /><span style="font-family: verdana, geneva, sans-serif; font-size: 12pt;">%s</span></p>
</div>''' % (Names, Title, Journal)
        else:
            outformat = '''<div>
<p class="body"><span style="font-family: verdana, geneva, sans-serif; font-size: 12pt;">%s</span><br /><span style="font-family: verdana, geneva, sans-serif; font-size: 12pt;"> <a target="_blank" href=%s><b>%s</b></a></span><br /><span style="font-family: verdana, geneva, sans-serif; font-size: 12pt;">%s</span></p>
</div>''' % (Names, doi, Title, Journal)

        return outformat


if __name__ == '__main__':
    fetcher = fetcher()

    # Loukas
    author = 'Loukas'
    targets = {
        '2017': 'https://scholar.google.com/citations?hl=en&user=Fg3oNxwAAAAJ&view_op=list_works&sortby=pubdate',
        #'2018': 'https://scholar.google.com/citations?hl=en&user=Fg3oNxwAAAAJ&view_op=list_works&sortby=pubdate',
        }



    for k in targets.keys():
        print(k)
        print('-' * 20)

        if type(targets[k]) == list:
            html = ''
            for url in targets[k]:
                html += fetcher.fetcher(url, k)
        else:
            url = targets[k]
            html = fetcher.fetcher(url, k)

        file = codecs.open('GS_%s_%s.txt' % (author, k), 'w', 'utf-8')
        file.write(html)
        file.close()

        print('\n'*2)
