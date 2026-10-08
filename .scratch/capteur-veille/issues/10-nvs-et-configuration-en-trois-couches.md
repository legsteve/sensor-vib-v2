# 10: NVS et configuration en trois couches

**Spec à lire :** Réseau et protocole serveur ; Persistance ; Détection

**What to build:**
- Trois couches (compilée, NVS, serveur) ; application quand `config_version` diffère, dans les deux sens.
- NVS écrite seulement dans ce cas ; bornes appliquées et signalées.
- `verbose_until` expire seul.
- Changement de mode → `init()` complète sans redémarrage.
- Emplacements WiFi en NVS, amorcés depuis le fichier local si vides.
- `boot_count` incrémenté une fois par démarrage à froid ; `nvs_get_stats()` journalisé.
- Tests natifs : fusion, bornes, version.

**Hors périmètre :** Mode recharge, portail.

**Test matériel :** Motion → Rotation → Motion côté serveur ; mode verbeux à courte expiration ; 20 démarrages par RESET.

**Blocked by:** 09

**Status:** needs-triage

## Critères d'acceptation
- [ ] Mode appliqué au cycle suivant
- [ ] NVS écrite seulement sur changement
- [ ] Le mode verbeux expire seul
- [ ] `nvs_get_stats()` stable sur 20 démarrages
- [ ] Valeur hors bornes corrigée et signalée
