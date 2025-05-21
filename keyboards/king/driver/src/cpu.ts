import os from 'os';

function mapLoad( {times}: os.CpuInfo ) {
  let ticks = 0;
  for (const [type, value] of Object.entries(times)) {
    ticks += value;
  }
  return {
    idle: times.idle,
    ticks,
  }
}

const cpuStats = os.cpus().map( mapLoad );

export function getLoad( i: number ) {
  const cpus = os.cpus();
  const current = mapLoad(cpus[i]);
  const idleDiff = current.idle - cpuStats[i].idle;
  const tickDiff = current.ticks - cpuStats[i].ticks;
  cpuStats[i] = current;
  return {
    idle: idleDiff,
    ticks: tickDiff,
    percent: (tickDiff-idleDiff) / tickDiff
  };
}

export function getLoads() {
  return cpuStats.map( (cpu, i) => getLoad(i) );
}
