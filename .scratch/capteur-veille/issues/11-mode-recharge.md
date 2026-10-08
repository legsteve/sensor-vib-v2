# 11: Mode recharge

**Spec à lire :** Mode recharge et portail de configuration ; Matériel

**What to build:**
- VBUS lu au démarrage et à chaque réveil.
- En charge : éveillé, EXT1 non armé, aucune détection ; signe de vie « en charge » + tension toutes les 15 min.
- Redémarrage au débranchement.
- Décision testée en `native`.

**Hors périmètre :** Portail.

**Test matériel :** Chargeur mural 1 h, puis 10 débranchements.

**Blocked by:** 10

**Status:** needs-triage

## Critères d'acceptation
- [ ] Signe de vie toutes les 15 min, à la minute près
- [ ] Aucun mouvement rapporté pendant la charge
- [ ] 10/10 redémarrages propres
- [ ] La tension monte
