---
title: <%= @problem_name_cyr %>
type: standard #  tip zadatka, jedan od: "output-only", "standard", "functional"
timelimit: 2.0 # u sekundama
memlimit: 64   # u MB
setter: Младен Пузић      # pise tekst, kod i test primere
editorial: Младен Пузић   # onaj ko pise resenje
contributors: Павле Мартиновић # testeri, i ostali koji su doprineli zadatku
origin:  Младен Пузић  # ime onog ko je smislio zadatak / izvor zadatka
tags: [NZD]   # svaki zadatak treba ra je označen tagovima prema dogovorenoj listi tagova
solutions:  # referentna resenja zadatka 
  - name: full # sufiks koji se javlja u resenju, ovo znaci da treba da postoje fajlovi: problem_name-full.cpp i problem_name-full.pas
    lang: [cpp]
    desc: Главно решење # opis resenja
    tags: NZD# tagovi npr. brute force, trie...
    expected-status: ОК # jedan od: OK (podrazumevano), WA, TLE, MLE, RTE
owner:     # onaj ko ubacuje zadatak
status: IZRADA   # jedan od: "IZRADA", "PREGLED", "KANDIDAT" ili "KOMPLETAN".
status-od: <%= @danasnji_datum %>   # datum u formatu YYYY-MM-DD od kada je u navedenom statusu
---

