import torch
import snntorch as snn
import snntorch.functional as SF

lif = snn.Leaky(beta=0.9)
spk, mem = lif(torch.ones(1))
print(spk, mem)
