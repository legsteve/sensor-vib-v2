# 01: Ossature du dépôt

**Spec à lire :** Construction par paliers ; Protocole de test et de flash ; Interdits et pièges connus

**What to build:**
- Dépôt git initialisé, `.gitignore` (dont `logs/` et le fichier d'identifiants WiFi).
- PlatformIO avec trois envs : `native` (tests), `test` et `prod` ; CDC USB désactivé en `test` et `prod`.
- Un test natif minimal qui passe ; un firmware vide qui compile en `test` et en `prod`.
- `docs/DECISIONS.md` avec son format (date, env de build, MESURÉ ou SUPPOSÉ, conclusion).
- Un `CLAUDE.md` de sous-dossier pour l'accéléromètre et un pour l'alimentation/sommeil, courts, reprenant seulement les pièges qui les concernent.
- Le sous-agent `analyste-logs` (`.claude/agents/`) : lit un journal BLE, rend un verdict de 10 lignes au plus, ne recopie jamais le journal.
- Identifiants WiFi dans un fichier local ignoré par git, avec un exemple versionné.

**Hors périmètre :** Tout code fonctionnel (BLE, sommeil, capteur, WiFi).

**Test matériel :** Aucun.

**Blocked by:** None

**Status:** done

## Critères d'acceptation
- [x] `pio test -e native` passe
- [x] `pio run -e test` et `pio run -e prod` compilent
- [x] Le fichier d'identifiants est ignoré, l'exemple est versionné
- [x] `analyste-logs` existe
- [x] Les deux `CLAUDE.md` de sous-dossier existent
