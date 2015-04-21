
function draw_roc(labels, votes, title)

[X,Y,T,auc] = perfcurve(labels,votes,1);
h=figure(1);clf;plot(X,Y);hold on;plot([0 1],[0 1],':k');
xlabel('False positive rate'); ylabel('True positive rate');title(['ROC ', title]);
legend(sprintf('AUC = %.4f',auc));
 
end