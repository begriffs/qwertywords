#include <ctype.h>
#include <stdio.h>

int main(int argc, const char **argv)
{
	char line[512], *c, *prev;
	/* 0 is the left hand, 1 the right */
	short side[] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,0,0,1,0};
	/* letter pairs that roll off the fingers: po, oi, iu, lk, as, we, er */
	int roll[] = {'s',0,0,0,'r',0,0,0,'u',0,0,'k',0,0,'i','o',0,0,0,0,'i',0,'e',0,0,0};

	while (fgets(line, sizeof(line), stdin))
	{
		for (prev = NULL, c = line; isalpha(*c); prev = c++)
		{
			*c = tolower(*c);
			if (!prev)
				continue;
			if (side[(*prev)-'a'] == side[(*c)-'a'] && roll[(*prev)-'a'] != *c)
				break;
		}
		if (*c == '\n' || *c == '\0')
		{
			*c = '\0';
			puts(line);
		}
	}
	return 0;
}
