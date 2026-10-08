# 03: Sommeil et réveil par minuteur

**Spec à lire :** Architecture ; Sommeil et réveil ; Persistance ; Observabilité

**What to build:**
- Chemin unique `go_to_sleep()`, réveil par minuteur seul.
- Durée bornée 30 s – 4 h ; vérification de l'armement ; aucune source armée → redémarrage avec compteur (> 3 → minuteur 1 h).
- Causes de réveil et de reset journalisées ; diagnostics en `RTC_NOINIT_ATTR` rapportés par BLE au cycle suivant.
- Logique pure (bornage, décision de redémarrage) testée en `native`.

**Hors périmètre :** Accéléromètre, WiFi.

**Test matériel :** Env `test`, minuteur 30 s, 1 h sur batterie, selon le protocole de flash.

**Blocked by:** 02

**Status:** needs-triage

## Critères d'acceptation
- [ ] Aucun réveil manqué en 1 h (trous d'environ 30 s)
- [ ] Causes de réveil rapportées correctement
- [ ] Tests natifs verts
- [ ] Résultat consigné MESURÉ dans DECISIONS.md
