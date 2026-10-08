# 14: Endurance

**Spec à lire :** Construction par paliers ; Protocole de test et de flash

**What to build:**
- Env `prod` vérifié : ni LED ni BLE, constantes de production.
- Aucune autre fonctionnalité.

**Hors périmètre :** Toute nouvelle fonctionnalité.

**Test matériel :** Env `prod`, 72 h avec deux nuits, observation côté serveur.

**Blocked by:** 13, 06

**Status:** needs-triage

## Critères d'acceptation
- [ ] Heartbeats à l'heure, jour et nuit
- [ ] Chaque mouvement présent côté serveur
- [ ] `boot_count` inchangé
- [ ] Pente de tension et estimation d'autonomie dans DECISIONS.md
