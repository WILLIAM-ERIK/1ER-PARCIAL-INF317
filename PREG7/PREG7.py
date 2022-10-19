# -*- coding: utf-8 -*-
"""
Created on Mon Oct 17 22:26:46 2022

@author: ERIK
"""
p = 0
c = 1
tope=1000000
  
for i in range(tope): 
    if i % 2 == 0: 
        p = 4/c + p
    else: 
        p = p - 4/c 
    c = c + 2
print("PI=", p) 