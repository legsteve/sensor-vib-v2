# 04: Détection Motion et réveil par mouvement

**Spec à lire :** Détection ; Sommeil et réveil ; Matériel ; Interdits et pièges connus

**What to build:**
- `init()` complète du LIS2DW12 en Motion (soft reset, CTRL4 écrit en entier, LIR, CTRL7).
- Vérification des registres au réveil, réinit si écart.
- Garde INT1 avant sommeil : lecture par `rtc_gpio_get_level()`, 3 réacquittements, sinon minuteur 5 s seul + incident persisté.
- Adresse de `ALL_INT_SRC` vérifiée dans l'en-tête de la bibliothèque.
- Logique pure (garde, décision de sources) testée en `native`.

**Hors périmètre :** Rotation, WiFi, filtre.

**Test matériel :** Rappel 220 kΩ et condensateur 470 µF posés ; test rapide (mouvements à T+0, 2, 5, 10, 20, 40 min) observé par BLE.

**Blocked by:** 03

**Status:** needs-triage

## Critères d'acceptation
- [ ] 6/6 mouvements détectés
- [ ] Réveils minuteur réguliers entre les mouvements
- [ ] Aucun sommeil de moins de 5 s
- [ ] Registres de référence consignés MESURÉ
