# 13: État usine et mise en service

**Spec à lire :** Mode recharge et portail de configuration

**What to build:**
- Page device_id / jeton / serveur tant qu'aucune identité n'est en NVS.
- Elle disparaît ensuite et revient après un effacement complet ; le jeton n'est jamais réaffiché.

**Hors périmètre :** Tout le reste.

**Test matériel :** Effacer la flash, faire la mise en service, vérifier le premier événement côté serveur.

**Blocked by:** 12

**Status:** needs-triage

## Critères d'acceptation
- [ ] Flash effacée → premier événement accepté sans modifier le code
- [ ] Page absente après la mise en service
- [ ] Page réapparue après effacement
