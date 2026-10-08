# Décisions et conclusions

Toute conclusion technique est consignée ici. Une lecture de code donne
au mieux SUPPOSÉ ; seul un essai observé donne MESURÉ. Aucune conclusion
sur le sommeil depuis un build CDC actif ou un capteur branché en USB.

Les entrées s'ajoutent en bas, ne se modifient pas : une conclusion
contredite reçoit une nouvelle entrée qui cite l'ancienne.

## Format d'entrée

```
### AAAA-MM-JJ — Titre court
- Statut      : MESURÉ | SUPPOSÉ
- Ticket      : NN
- Env de build: native | test | prod  (+ commit court)
- Conditions  : alimentation (batterie / USB), CDC actif ou non, matériel
- Mesure      : ce qui a été observé (valeur, durée, fichier de log) ;
                « aucune » si SUPPOSÉ
- Conclusion  : la décision ou le constat, en une ou deux phrases
- Remplace    : date et titre de l'entrée contredite, sinon « — »
```

## Entrées

### 2026-10-08 — Chaîne de build validée
- Statut      : MESURÉ
- Ticket      : 01
- Env de build: native, test, prod (commit e5b6e9c)
- Conditions  : poste Windows, PowerShell, sans matériel
- Mesure      : `pio test -e native` PASSED (1/1) ; `pio run -e test`
                SUCCESS (flash 18,4 %, 240 964 o ; RAM 4,3 %) ;
                `pio run -e prod` SUCCESS. Versions résolues : espressif32
                55.3.312 (pioarduino stable), framework-arduinoespressif32
                3.3.12, framework-arduinoespressif32-libs 5.5.5, ESP-IDF
                5.5.5, toolchain-riscv32-esp 14.2.0+20260121, esptool 5.4.0,
                Unity 2.6.1.
- Conclusion  : la plateforme pioarduino et la carte seeed_xiao_esp32c6
                compilent les trois envs. L'URL `stable` n'est pas figée.
- Remplace    : —

### 2026-10-08 — CDC USB désactivé à la compilation
- Statut      : MESURÉ pour prod, SUPPOSÉ pour test ; SUPPOSÉ sur la carte
- Ticket      : 01
- Env de build: test, prod (commit e5b6e9c)
- Conditions  : build verbeux, poste Windows, sans matériel
- Mesure      : `pio run -v` : 63 occurrences de ARDUINO_USB_CDC_ON_BOOT=0
                et 1 de =1, pour test comme pour prod. En prod, le =1 vient
                de l'en-tête « Processing » et d'aucune ligne de
                compilation riscv32. Ce contrôle n'a pas été refait en test.
- Conclusion  : le drapeau vaut 0 sur toutes les compilations prod, et
                très probablement en test (mêmes comptes). Que le CDC soit
                inactif sur la carte reste à observer au premier flash.
- Remplace    : —
