#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

char*
sys_mmap(void)
{
  void* addr=0;
  uint length, offset;
  int prot, flags, fd;
  struct proc *p = myproc();

  argptr(0, addr, sizeof(void*));
  argint(1, (int*)&length);
  argint(2, &prot);
  argint(3, &flags);
  argint(4, &fd);
  argint(5, (int*)&offset);

  length = PGROUNDUP(length);//considering address at the beggining of the new page

  struct mapped_mem *m = &(p->files[p->file_count]);
  p->file_count++;
  m->start = p->last_addr;
  m->end = m->start + length;
  p->last_addr = m->end;
  m->fd = fd;
  m->len = length;
  m->prot = prot;
  m->file = p->ofile[fd];

  filedup(m->file);

  return m->start;
}
