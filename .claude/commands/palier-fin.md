---
description: Clôt le palier courant (vérifications, PROGRESS, DECISIONS, commit)
---

Clôture du palier courant. Résultat d'essai fourni par l'humain :
$ARGUMENTS

1. Lis docs/PROGRESS.md et la fiche docs/paliers/PN.md.
2. Lance `pio test -e native`, puis `pio run -e test` et
   `pio run -e prod`. Note le résultat de chacun.
3. Si un journal est fourni, fais-le analyser par l'agent
   analyste-logs ; ne le lis pas ici.
4. Fais relire le diff par l'agent relecteur. Un point BLOQUANT arrête
   la clôture.
5. Le palier n'est validé que si le critère de sortie est atteint par
   une mesure (MESURÉ). Sinon : statut « échec » ou « en cours »,
   aucune clôture, et le palier suivant ne démarre pas.
6. Ajoute à docs/DECISIONS.md une entrée par conclusion, au format du
   fichier (MESURÉ / SUPPOSÉ, date, env de build, conditions, mesure).
7. Mets docs/PROGRESS.md à jour : palier validé dans l'historique,
   palier suivant courant avec statut « à démarrer », prochaine action,
   dernier résultat de test, hypothèses ouvertes, problèmes hors
   périmètre.
8. Commit unique du palier ; le message contient le résultat du test :
   `PN : <titre> — <critère> : RÉUSSI (<mesure>, env <env>)`.
9. Rappelle à l'humain de lancer /clear.
