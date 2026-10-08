# 05: Détection Rotation

**Spec à lire :** Détection

**What to build:**
- Détection 6D ; mode choisi à la compilation.
- Ouverture comme fermeture = mouvement.
- Calibration de la position « fermé » journalisée.

**Hors périmètre :** Angle et durée (v2) ; bascule de mode à chaud (ticket 10).

**Test matériel :** Capteur sur une vraie porte : test rapide, puis 40 min immobile avec de l'activité autour.

**Blocked by:** 04

**Status:** needs-triage

## Critères d'acceptation
- [ ] 6/6 ouvertures détectées
- [ ] Aucun réveil par mouvement pendant 40 min immobile
- [ ] Registres Rotation consignés MESURÉ
