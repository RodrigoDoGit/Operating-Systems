#include <sys/types.h>
/* ... */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

   if (argc != 3 ) {
      (void)fprintf(stderr, "usage: %s perms file\n", argv[0]);
      return EXIT_FAILURE;
   }

   int perms = atoi(argv[1]);
   int operms = perms % 10;
   perms = perms / 10;
   int gperms = perms % 10;
   perms = perms / 10;
   int uperms = perms;

   mode_t newperms = (mode_t)0;

   switch (uperms) {
      case 0: break;
      case 1: /* ... */
      case 2: /* ... */
      case 3: /* ... */
      case 4: newperms |= S_IRUSR; break;
      case 5: newperms |= S_IRUSR | S_IXUSR; break;
      case 6: newperms |= S_IRUSR | S_IWUSR; break;
      case 7: /* ... */
      default:
              (void)fprintf(stderr, "%s: illegal permission value\n", argv[0]);
              /* ... */
   }

   switch (gperms) {
      case 0: /* ... */
      case 1: newperms |= S_IXGRP; break;
      case 2: newperms |= S_IWGRP; break;
      case 3: newperms |= S_IWGRP | S_IXGRP; break;
      case 4: /* ... */
      case 5: /* ... */
      case 6: newperms |= S_IRGRP | S_IWGRP; break;
      case 7: newperms |= S_IRGRP | S_IWGRP | S_IXGRP; break;
      default:
              /* ... */
              return EXIT_FAILURE;
   }

   switch (operms) {
      case 0: break;
      case 1: newperms |= S_IXOTH; break;
      case 2: newperms |= S_IWOTH; break;
      case 3: /* ... */
      case 4: newperms |= S_IROTH; break;
      case 5: newperms |= S_IROTH | S_IXOTH; break;
      case 6: /* ... */
      case 7: /* ... */
      default:
              (void)fprintf(stderr, "%s: illegal permission value\n", argv[0]);
              return EXIT_FAILURE;
   }

   if (chmod(argv[2], newperms) == -1) {
      (void)fprintf(stderr, "%s: cannot chmod %s\n", argv[0], argv[2]);
      return EXIT_FAILURE;
   }
   /* ... */
}
