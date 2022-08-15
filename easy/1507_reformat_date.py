class Solution:
    def reformatDate(self, date: str) -> str:
        day, month, year = tuple(date.split(' '))
        day = day.replace('st', '').replace('nd', '').replace('rd', '').replace('th', '')
        day = '0' + day if len(day) < 2 else day
        month = {
            'Jan': '01',
            'Feb': '02',
            'Mar': '03',
            'Apr': '04',
            'May': '05',
            'Jun': '06',
            'Jul': '07',
            'Aug': '08',
            'Sep': '09',
            'Oct': '10',
            'Nov': '11',
            'Dec': '12'
        }[month]
        return '{}-{}-{}'.format(year, month, day)
