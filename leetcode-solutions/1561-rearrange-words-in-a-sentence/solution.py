class Solution(object):
    def arrangeWords(self, text):
        return " ".join(sorted(text.split(),key=len)).lower().capitalize()

    
        """
        :type text: str
        :rtype: str
        """
        
