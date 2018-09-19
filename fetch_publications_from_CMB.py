#!/Users/p6n/tools/anaconda2/bin/python

import urllib2, os
import unicodedata
import codecs
from bs4 import BeautifulSoup

class fetcher:
    def __init__(self):
        return

    def fetcher(self, url):
        fcon = []
        pubs, dois = self.pub_fetcher(url)

        for p, d in zip(pubs, dois):
            line = self.format_pub_html(p, d)
            fcon.append(line)

        fcon_html = '\n'.join(fcon)

        return fcon_html



    def pub_fetcher(self, url):
        '''
        only works for cmb old website!
        '''
        soup = BeautifulSoup(urllib2.urlopen(url), features="lxml")
        pubs = soup.find_all('p', attrs={'class': 'body'})

        dois = []
        for pub in pubs:
            a = pub.find('a')
            href = a.attrs['href']

            doi = ''
            try:
                doi = self.doi_fetcher(href)
            except:
                print('Cannot find doi for %s' % pub.text)

            dois.append(doi)

        return pubs, dois

    def doi_fetcher(self, url):
        '''
        only works for cmb old website!
        find the doi address
        '''
        soup = BeautifulSoup(urllib2.urlopen(url), features="lxml")
        divs = soup.find_all('div', attrs={'class': 'field'})

        for d in divs:
            if d.text.find('URL') > 0:
                href = d.find('a').attrs['href']

        return href

    def format_pub_html(self, pub, doi):

        Names = pub.contents[0].replace(u'\xa0', '&nbsp;')
        Title = pub.find('b').text
        Journal = pub.contents[-1].replace(u'\xa0', '&nbsp;')

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

    targets = {
        '2006': 'http://cmb.ornl.gov/publications/2006',
        '2007': 'http://cmb.ornl.gov/publications/2007',
        '2008': 'http://cmb.ornl.gov/publications/2008',
        '2009': 'http://cmb.ornl.gov/publications/2009',
        '2010': 'http://cmb.ornl.gov/publications/2010',
        '2011': ['http://cmb.ornl.gov/publications/2011', 'http://cmb.ornl.gov/publications/2011/base_view?b_start:int=25&-C='],
        '2012': ['http://cmb.ornl.gov/publications/2012', 'http://cmb.ornl.gov/publications/2012/base_view?b_start:int=25&-C='],
        '2013': ['http://cmb.ornl.gov/publications/2013', 'http://cmb.ornl.gov/publications/2013/base_view?b_start:int=25&-C='],
        '2014': ['http://cmb.ornl.gov/publications/2014', 'http://cmb.ornl.gov/publications/2014/base_view?b_start:int=25&-C='],
        '2015': ['http://cmb.ornl.gov/publications/2015', 'http://cmb.ornl.gov/publications/2015/base_view?b_start:int=25&-C='],
        '2016': ['http://cmb.ornl.gov/publications/2016', 'http://cmb.ornl.gov/publications/2016/base_view?b_start:int=25&-C='],
        '2017': 'http://cmb.ornl.gov/publications/2017',
        }

    for k in targets.keys():
        print(k)
        print('-' * 20)

        if type(targets[k]) == list:
            html = ''
            for url in targets[k]:
                html += fetcher.fetcher(url)
        else:
            url = targets[k]
            html = fetcher.fetcher(url)

        #html = unicodedata.normalize('NFKD', html).encode('ascii','ignore')
        #html = html.replace(u'\u2013', '-')
        #open('%s.txt' % k, 'w').write(html)

        file = codecs.open('%s.txt' % k, 'w', 'utf-8')
        file.write(html)
        file.close()

        print('\n'*2)
