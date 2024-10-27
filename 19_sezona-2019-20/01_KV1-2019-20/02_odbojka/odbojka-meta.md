---
title: <%= @problem_name_cyr %>
type:  #  tip zadatka, jedan od: "output-only", "standard", "functional"
timelimit: 1.0 # u sekundama
memlimit: 64   # u MB
setter: Filip Ćosović # pise tekst, kod i test primere
editorial: Nikola Jovanović # onaj ko pise resenje
contributors: Marko Savić # testeri, i ostali koji su doprineli zadatku
origin: Nikola Milosavljević # ime onog ko je smislio zadatak / izvor zadatka
tags: []   # svaki zadatak treba ra je označen tagovima prema dogovorenoj listi tagova
solutions:  # referentna resenja zadatka 
  - name: ex0 # podrazumevani sufiks, odgovara resenju problem_name.cpp
    lang: [cpp]
  - name: full # sufiks koji se javlja u resenju, ovo znaci da treba da postoje fajlovi: problem_name-full.cpp i problem_name-full.pas
    lang: [cpp, pas]
    desc: # opis resenja
    tags: # tagovi npr. brute force, trie...
    expected-status: # jedan od: OK (podrazumevano), WA, TLE, MLE, RTE
owner:     # onaj ko ubacuje zadatak
status: IZRADA   # jedan od: "IZRADA", "PREGLED", "KANDIDAT" ili "KOMPLETAN".
status-od: <%= @danasnji_datum %>   # datum u formatu YYYY-MM-DD od kada je u navedenom statusu
---

